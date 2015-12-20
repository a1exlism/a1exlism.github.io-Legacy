Using the JavaScript language, have the function DivisionStringified(num1,num2)
 take both parameters being passed, 
 divide num1 by num2, and return the result as a string with properly formatted commas. 
 If an answer is only 3 digits long, return the number with no commas (ie. 2 / 3 should output "1"). 
For example: if num1 is 123456789 and num2 is 10000 the output should be "12,346". 

Input = 5 & num2 = 2			Output = "3"
Input = 6874 & num2 = 67	Output = "103"

//实现:1.向上进位 2.添加逗号
function DivisionStringified(num1,num2) { 
	if( num1 < 10 && num2 < 10)
		return 1;
	var result = num1 / num2;
	
	// code goes here  
	return num1 + num2; 
	       
}