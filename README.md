online-judge
============
online programming learning

---------------------------------------------------------
Part one:t.jobdu.com
---------------------------------------------------------
1000:	a+b	
file:	part-one-1000.c	
status:	ac
notes:	scanf() returns EOF(end of file) if there is something wrong or the reading is headed to the real end of the file.
	
---------------------------------------------------------
1001:	a+b for matrices
file:	part-one-1001.c
status:	ac	
notes:	remeber the difference between int and int*
	remeber the way to declare the 2-dimension array 
	remeber to free the dynamic array when finished and the way to free it

---------------------------------------------------------
1002:	grading
file:	part-one-1002.c
status:	ac
notes:	bool is not supported in this online judge
	formulization of the result is very strict and important

---------------------------------------------------------
1003:	A+B
file:	part-one-1003.c
status: ac
notes:	the way to get each 'char' is easy to time out
	so, use scanf("%s %s",a,b) to instead getchar()

----------------------------------------------------------
1004:	find mideum
file:	part-one-1004-pre.c:solve the sub-question which the length of two array is the same
	part-one-1004.c
status: ac
notes:	the main idea of 1004 is to change the length of a and b to the same,as this sub-question is solved in part-one-1004-pre.c
        but the question is how to change?
        1. as you may see in part-one-1004.c,when all in a is bigger then all in b the problem is easy to solve,
        the same with all in b is bigger then all in a
        2.if the length diff of a and b is even, after step 1 you will find out the begin of longer must smaller then the midium ,
        so does the end.so you can cut the longer to the same length with shorter
        3.if the length diff of a and b is odd, you may need to add a number to the end of the shorter one,
	because when cut by diff/2 the longer still has one more item then the shorter
	4.the all for the code.But why you can do it like the above said?
          some properties of medium can make sure that you will find the right answer.
	    First:when you are given a sequence which is monotonic decreasing.
		if the length of this sequence is odd,
		  the medium is (begin+end)/2+1,means that there are (begin+end)/2 numbers is smaller then medium 
		  and there are the same numbers which are bigger then medium
		if length is even,
		  there are (begin+end)/2-1 which are smaller then medium 
		  and there (begin+end)/2 which are bigger then medium
	    Second:when the sequence given you is odd,when you add a bingger enough number to the end,the medium would not change. 
	--------------------------------------------------------------

	----------------------------------------------------------------
	----------------------------------------------------------------
	move on to usaco,as it's environment is better!
	-----------------------------------------------

















