/*-------基于javascript的弱类型语言,需要强制取整数类型---------
*floor,		round,			ceil--------
*向下取整 	四舍五入			向上取整-----
*/
function TimeConvert(num) { 
  // code goes here  
  return parseInt(num/60) + ':' + num%60  ; 
  //parseInt()强制取整 
}
   
// keep this function call here 
// to see how to enter arguments in JavaScript scroll down
TimeConvert(readline());

//这个太简单了...