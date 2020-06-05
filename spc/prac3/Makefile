delete:
	rm smsh1 smsh2
smsh1: smsh1.c splitline.c execute.c
	gcc $^ -o $@
part1: smsh2.c execute2.c splitline.c
	gcc -o smsh2 $^
part2: smsh3.c execute3.c splitline.c
	gcc -o smsh3 $^
part3: smsh4.c execute4.c splitline.c
	gcc -o smsh4 $^
