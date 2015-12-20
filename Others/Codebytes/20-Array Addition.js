function ArrayAdditionI(arr) { 
	arr.sort(function(a,b){
		return a-b;
	});
	//var max = arr.pop();
	//splice()返回的是一个数组对象
	var max = arr.splice( arr.length-1, 1);
	var sum = i = 0;
	var result = false;
	var arrPlus = function( sum, i){

		if( sum == max ){	//   === 会导致类型也强制匹配,导致splice()返回的数组对象无法相等
			result = true;
			return  ;
		}
		for( ; i < arr.length; i++){		//一次循环内只跑一个数,下次i++之前需要将sum还原
			sum += arr[i];
			arrPlus( sum ,i+1);
			sum -= arr[i];
		}
	};
	arrPlus( sum ,i);
	return result;
}