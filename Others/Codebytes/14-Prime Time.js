//---------这个错误了,然而并没有检测出来= =---------
function PrimeTime(num) { 
	for( var i = 2;i <  Math.sqrt(num) ; i++){
		if( num %  i === 0)
			return false;
	}	
  // code goes here  
  return true; 
         
}
//--------修正---------
function PrimeTime(num) { 
	for( var i = 2;i <  Math.sqrt(num) + 1 ; i++){
		if( ! (num %  i) )
			return false;
	}	
  return true; 
}
//----这个回去补充----
/*信息安全数学基础 张焕炯*/

//--------Others'1---------
/*
*		有人考虑到了算法问题
*/
function PrimeTime(num) { 
  var n = parseInt(num, 10);
  
  if (n 