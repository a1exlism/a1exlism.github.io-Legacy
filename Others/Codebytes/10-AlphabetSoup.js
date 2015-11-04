/*-----学习了正则表达式,坑------
*---Nice-->http://www.regexr.com/
*/
//---------failed1-------
function AlphabetSoup(str) { 
	str = str.replace(/[^a-z+A-Z]/,'');	//这个可以好好看看

  // code goes here  
  return str; 
         
}
//----------2------
function AlphabetSoup(str){
	var newStr = '';
	for(var i = 0 ;i < str.length; i++){
		if( str[i] >= 'a'&& str[i] <= 'z'="" ||="" str[i]="">= 'A' && str[i] </=>