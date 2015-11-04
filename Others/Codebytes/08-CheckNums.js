function CheckNums(num1,num2) { 
	if(num1 < num2)
		return true;
  // code goes here  
	else if(num1 > num2)
		return false;
	else(num1 === num2)         
		return -1;
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
CheckNums(readline());

//--------Others'1--------
/*
*------排名第一的还是这么吊...----
*/
function CheckNums(num1, num2){
	if( num1 === num2 )
		return -1;
	return num1 < num2;	//返回的是一个boolen类型
}
//--------Others'2--------
/*
*	-----思想一样------
*/
function CheckNums(num1, num2){
	return num2 == num1 ? -1 : num2 > num1 ;
}