# Bitshit
A programming language that can only process bits.

# Example
Bishit follows very simple rules. A character followed by a bit will set a variable to the value of the bit. Variable names cannot be longer than a character, and there must not be any spaces. Anything after the declaration/assignment on a line is classed as a comment.

```
00    define 0 = 0 and 1 = 1 makes it so that we can use these values
11

+ A line starting with a plus is a comment

a0    set the value of a to 0, or create it with 0 if it doesn't already exist
b1    set the value of b to 1, or create it with 1 if it doesn't already exist

c:a=b   compare a equals b, placing the result in c
d:c!b   compare c does not equal b, placing the result in b

[c]   anything between [ and ] gets it's value printed to the screen

e,    a character followed by a comma will take input (either 1 or 0) and place it in the variable
[e]   print e
```
