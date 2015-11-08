//--------思路 正则--------
function ExOh(str) { 
	if( !(/[o]/.test(str)) || !(/[x]/.test(str)))
		//判断是否存在,测试之后才知道自己没有放入..
		return false;
	var os =  str.match(/[o]/g);
	var xs = str.match(/[x]/g);
	// if( os === null || xs === null)
	// 	return false;		可以用这个来代替
	return (os.length === xs.length);
	//比较数组长度
}

//-----------Others'1---------
function ExOh(str) { 
  //这个真的好想法...拿笔看看...
  //温习了split()	split()以()内的符号为分隔符()内的内容不放入数组,
  //下面数组长度都为5
    return str.split(/x/i).length === str.split(/o/i).length; 
}
//----------Others'2---------
