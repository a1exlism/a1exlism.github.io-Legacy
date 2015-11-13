//-----错误----------
function divisor(a, b){	//最大公约数
	q = Math.floor( a / b );
	r = a % b;
	if( r == 0)
		return a;
	else
		return divisor( q, r );
}
//--------Version2-----------
function divisor(a, b){	//最大公约数
	if ( a < b ){
		var tmp = a;
		a = b;
		b = tmp;
	}
	var c = a % b;
	while( c !== 0){
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
function multiple( a, b ){		//最小公倍数
	return a * b / divisor( a, b );
}
function main( arr ){		//arr.prototype = Array();
	var sum = multiple( arr[0] , arr[1] );
	for( i = 2; i < arr.length ; i++ ){
		sum = multiple( sum , arr[i] );
	}
	return sum;
}
var num = new Array( 1, 2, 3, 4, 5);
main( num );
