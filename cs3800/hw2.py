# Dylan Elznic
# CS 3800 Assignment 2

import sys
import math
import datetime

# Input handling
inputErrors = ['Programlist file',
			   'Programtrace file',
			   'Pagesize (positive power of 2)',
			   'Page replacement algorithm (Clock, FIFO, or LRU)',
			   'Demand/prepaging (0 = demand, 1 = prepaging)',
			   ]

def checkExists():
	try:
		temp = sys.argv[i]
	except:
		print('\n> Missing input for Input {}: "{}".\n'.format(i, inputErrors[i-1]))
		exit()

def invalidInput():
	print('\n> Invalid input for Input {}: "{}"\n'.format(i, inputErrors[i-1]))
	exit()

for i in range(1,6):
	if i == 1 or i == 2:
		try:
			open(sys.argv[i])
		except:
			invalidInput()
	elif i == 3:
		checkExists()
		if int(sys.argv[i]) not in [1, 2, 4, 8, 16]:
			invalidInput()
	elif i == 4:
		checkExists()
		if sys.argv[i] not in ['Clock', 'FIFO', 'LRU']:
			invalidInput()
	elif i == 5:
		checkExists()
		if int(sys.argv[i]) not in [0, 1]:
			invalidInput()
# End input handling

class MainMemory(object):
	AVAILABLE_PAGES = 512
	page_size = int(sys.argv[3])
	num_pages = math.floor(AVAILABLE_PAGES / page_size)
	page_tables = []
	active_pages = []
	active_times = []
	active_clock = []

class PageTable(object):
	program_number = 0
	program_size = 0
	page_size = 0
	pages_needed = 0
	unique_id_no = []

	def __init__(self, pnum, prsize, pasize, paneed, idno):
		self.program_number = pnum
		self.program_size = prsize
		self.page_size = pasize
		self.pages_needed = paneed
		self.unique_id_no = idno

workingMemory = MainMemory()

id_index = 0
c_pointer = 0
page_faults = 0
temp_prognum = 0
temp_progsize = 0
temp_rel_word = 0
temp_abs_page = 0
temp_abs_name = 0
algorithm = sys.argv[4]

if sys.argv[5] == '0':
	paging_mode = 'demandpaging'
elif sys.argv[5] == '1':
	paging_mode = 'prepaging'

# Parse programlist and assign pages to programs
with open(sys.argv[1]) as f:
	for line in f:
		temp_line = line.split()
		temp_prognum = int(temp_line[0])
		temp_progsize = int(temp_line[1])
		temp_paneed = math.floor(temp_progsize / workingMemory.page_size)
		temp_idno = []

		for i in range(id_index, id_index + temp_progsize):
			temp_idno.append(i)
		id_index += temp_progsize

		# Create new PageTable
		workingMemory.page_tables.append(
			PageTable(temp_prognum, temp_progsize, 
				workingMemory.page_size, temp_paneed, temp_idno))

allocated_pages = math.floor(workingMemory.num_pages / len(workingMemory.page_tables))

# Initial memory loading
for program in workingMemory.page_tables:
	if program.pages_needed < allocated_pages:
		for j in range(program.pages_needed):
			workingMemory.active_pages.append(program.unique_id_no[j])
			workingMemory.active_times.append(datetime.datetime.now())
			workingMemory.active_clock.append(1)
		for k in range(allocated_pages - program.pages_needed):
			workingMemory.active_pages.append('')
			workingMemory.active_times.append(datetime.datetime.now())
			workingMemory.active_clock.append(1)
	else:
		for n in range(allocated_pages):
			MainMemory.active_pages.append(program.unique_id_no[n])
			workingMemory.active_times.append(datetime.datetime.now())
			workingMemory.active_clock.append(1)

# Programtrace handling
with open(sys.argv[2]) as f:
	for line in f:
		temp_line = line.split()
		temp_prognum = int(temp_line[0])
		temp_rel_word = int(temp_line[1])
		temp_abs_page = math.floor(temp_rel_word / workingMemory.page_size)

		temp_abs_name = workingMemory.page_tables[temp_prognum].unique_id_no[temp_abs_page]
		temp_abs_next = workingMemory.page_tables[temp_prognum].unique_id_no[temp_abs_page + 1]

		if temp_abs_name in workingMemory.active_pages:
			location = workingMemory.active_pages.index(temp_abs_name)
			if algorithm == 'LRU':
				workingMemory.active_times[location] = datetime.datetime.now()	
			elif algorithm == 'Clock':
				workingMemory.active_clock[location] = 1
		
		else:
			page_faults += 1
			
			if algorithm == 'LRU':
				oldest = workingMemory.active_times.index(min(workingMemory.active_times))
				workingMemory.active_pages[oldest] = temp_abs_name
				workingMemory.active_times[oldest] = datetime.datetime.now()
				if paging_mode == 'prepaging':
					oldest = workingMemory.active_times.index(min(workingMemory.active_times))
					workingMemory.active_pages[oldest] = temp_abs_next
					workingMemory.active_times[oldest] = datetime.datetime.now()
			
			elif algorithm == 'Clock':
				found1 = False
				found2 = True
				if paging_mode == 'prepaging':
					found2 = False	

				if '' in workingMemory.active_pages:
					blank = workingMemory.active_pages.index('')
					workingMemory.active_pages[blank] = temp_abs_name
				else:
						while not found1 or not found2:
							if workingMemory.active_clock[c_pointer] == 0:
								workingMemory.active_clock[c_pointer] = 1
								if found1 == True:
									temp_abs_name = temp_abs_next
								workingMemory.active_pages[c_pointer] = temp_abs_name
								c_pointer += 1
								if found1 == True:
									found2 = True
								found1 = True
							else:
								workingMemory.active_clock[c_pointer] = 0
								c_pointer += 1
							if c_pointer >= len(workingMemory.active_pages):
								c_pointer = 0

			elif algorithm == 'FIFO':
				oldest = workingMemory.active_times.index(min(workingMemory.active_times))
				workingMemory.active_pages[oldest] = temp_abs_name
				workingMemory.active_times[oldest] = datetime.datetime.now()
				if paging_mode == 'prepaging':
					oldest = workingMemory.active_times.index(min(workingMemory.active_times))
					workingMemory.active_pages[oldest] = temp_abs_next
					workingMemory.active_times[oldest] = datetime.datetime.now()

print('\n{0} - {1} = {2} page faults\n'.format(algorithm, paging_mode, page_faults))