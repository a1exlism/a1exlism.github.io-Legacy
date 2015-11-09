//--------添加两个flag指示--------
function ArithGeo(arr) { 
	var flag1 = flag2 = 1;
	var x1 = arr[1] - arr[0];
	var x2 = arr[1] / arr[0];
	for( var i = 1; i < arr.length - 1; i++){
		if( x1 != arr[i+1] - arr[i] )
			flag1 = 0;
		if( x2 != arr[i+1] / arr[i])
			flag2 = 0;
	}
	switch( flag1 - flag2){
		case 1 :
			return	'Arithmetic';
		case -1 :
			return	'Geometric';
		case 0 :
			return -1;
	} 
}

//----------Others'1---------
//-----发现其他人的代码都差不多...