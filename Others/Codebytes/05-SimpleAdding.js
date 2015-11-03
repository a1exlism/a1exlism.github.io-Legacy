function SimpleAdding(num) { 
	num = (num + 1) * num /2;
  // code goes here  
  return num; 
         
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
SimpleAdding(readline());                            

//----------Others'------------
function SimpleAdding(num){
	if(num == 1)
		return 1;
	else
		return num + SimpleAdding(num - 1);
}	//递归调用
