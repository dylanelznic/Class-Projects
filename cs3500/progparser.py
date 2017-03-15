"""
	Dylan Elznic
	CS 3500 Section 1A
	Homework 3
"""

"""   TOKENS   """

def isInt(token):
	#Check for prefix '+' or '-' in string, then remove it
	for prefix in ['+','-']:
		if prefix in token:
			token = token.replace(prefix, '')

	#Check if the token is all digits
	if token.isdigit():
		return True

def isDec(token):
	#Check for prefix '+' or '-' in string, then remove it
	for prefix in ['+','-']:
		if prefix in token:
			token = token.replace(prefix, '')

	#Check for decimal within number, then remove it
	for char in token:
		if char == '.':
			token = token.replace(char, '')

	if token.isdigit():
		return True

def isString(token):
	if token[0] == '"':
		if token[len(token) - 1] == '"':
			return True

	return False

def isKeyword(token):
	for key in [':=', '+', '-', '*', '/', 'OR', 'AND', '~', '(', ')', '<', 
				'>','=' , '#', '&', '!', 'PRINT', 'IF', 'ELSE', 'FI', 'LOOP', 
				'POOL', 'FUNC', 'RET',  'BEGIN', 'END']:
		if key == token:
			return True

def isIdentifier(token):
	isId = False
	if token[0].isalpha():
		isId = True
		for char in token:
			if not char.isalnum():
				isId = False

	if isId == True:
		return True

"""   OPERATORS   """

def Relation():
	global index, token, test, limit

	if index < limit:
		for key in ['<', '>', '=', '#']:
			if key == token[index]:
				get_token()
				return True
	return False

def AddOperator():
	global index, token, test, limit

	if index < limit:
		for key in ['+', '-', 'OR', '&']:
			if key == token[index]:
				get_token()
				return True
	return False

def MulOperator():
	global index, token, test, limit

	if index < limit:
		for key in ['*', '/', 'AND']:
			if key == token[index]:
				get_token()
				return True
	return False

"""   Expressions   """

def Expression():
	SimpleExpression()
	ExpressionMod()

def ExpressionMod():
	Relation()
	SimpleExpression()

def SimpleExpression():
	Term()
	while AddOperator():
		Term()

def Term():
	Factor()
	while MulOperator():
		Factor()

def Factor():
	global index, token, test, limit
	pcheck = 0

	if index <= limit:
		if token[index] == '(':
			get_token()
			Expression()
			pcheck = 1
		elif token[index] == '~':
			get_token()
			Factor()
		elif isInt(token[index]) or isDec(token[index]) or isString(token[index]) or isIdentifier(token[index]):
			get_token()

	if index < limit:
		if token[index] == ')' and pcheck == 1:
			get_token()

"""   Statements   """

def Statement():
	global index, token, test, limit

	if Assignment():
		Assignment()
		return True
	if PrintStatement():
		PrintStatement()
		return True
	if RetStatement():
		PrintStatement()
		return True
	if IfStatement():
		IfStatement()
		return True
	if LoopStatement():
		LoopStatement()
		return True

def StatementSequence():
	global index, token, test, limit

	Statement()

	while Statement():
		Statement()

def Assignment():
	global index, token, test, limit

	if isIdentifier(token[index]):
		get_token()
		if token[index] == ':=':
			get_token()
			Expression()
			if token[index] == "!":
				get_token()
				return True
		else:
			index = index - 1
			test[index] = None

def PrintStatement():
	global index, token, test, limit

	if token[index] == 'PRINT':
		get_token()
		if token[index] == '(':
			get_token()
			Expression()
			if token[index] == ')':
				get_token()
				if token[index] == '!':
					get_token()
					return True

def RetStatement():
	global index, token, test, limit
	
	if token[index] == 'RET':
		get_token()
		if isIdentifier(token[index]):
			get_token()
			if token[index] == '!':
				get_token()
				return True


def IfStatement():
	global index, token, test, limit

	if token[index] == 'IF':
		get_token()
		if token[index] == '(':
			get_token()
			Expression()
			if token[index] == ')':
				get_token()
				StatementSequence()
				IfStatementMod()
				if token[index] == 'FI':
					get_token()
					return True

	return False

def IfStatementMod():
	global index, token, test, limit

	if token[index] == 'ELSE':
		get_token()
		StatementSequence()

def LoopStatement():
	global index, token, test, limit

	if token[index] == 'LOOP':
		get_token()
		if token[index] == '(':
			get_token()
			Expression()
			if token[index] == ')':
				get_token()
				StatementSequence()
				if token[index] == 'POOL':
					get_token()
					return True


""" Parameter Sequence """
def ParamSequence():
	global index, token, test, limit

	if index <= limit:
		if isIdentifier(token[index]):
			get_token()
		if index < limit:
			if token[index] == ',':
				get_token()
				ParamSequence()

""" Functions """
def FunctionSequence():
	global index, token, test, limit

	FunctionDeclaration()

	i = 0

	while index < limit and i < 200: 		#Assuming all code is encapsulated within a function!
		FunctionDeclaration()
		i += 1

def FunctionDeclaration():
	global index, token, test, limit

	if token[index] == 'FUNC':
		get_token()
		if isIdentifier(token[index]):
			get_token()
			if token[index] == '(':
				get_token()
				ParamSequence()
				if token[index] == ')':
					get_token()
					if token[index] == 'BEGIN':
						get_token()
						StatementSequence()
						if token[index] == 'END.':
							get_token()

""" Get Token """

def get_token():
	global index, token, test, limit

	test[index] = token[index]
	index += 1

"""   MAIN   """

index = 0
result = False

#Open file
file = open('test.txt')

#Input file into a string, then split into tokens
token = file.read()
token = token.split()
test = [None] * len(token)
limit = len(token) - 1

testHolder = test
indexHolder = index

FunctionSequence()
if test == token:
	result = True

if result == True:
	print("CORRECT")
else:
	print("INVALID!")

#Close file
file.close()

""" For Testing

	print()
	print("Index: ", index)
	print("Token: ", token)
	print("Test: ", test)
	print("Limit: ", limit)
	print()
"""