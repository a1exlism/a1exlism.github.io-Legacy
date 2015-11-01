function FirstReverse(str) { 
	var i = 0;
	var reverseStr = new String();
	while(i < str.length){
		reverseStr += str[str.length -1 - i++];
	}

  // code goes here  
  return reverseStr; 
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
FirstReverse(readline());                            