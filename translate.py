

with open("testfile2","w") as g:
	with open("testfile1","r") as f:
		a = ""
		while a is not None:
			a = f.readline()
			if a is not None:
				g.write("TOKEN_" + a.split()[1] + " ")
