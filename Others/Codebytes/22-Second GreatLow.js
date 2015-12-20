function SecondGreatLow(arr) { 
	if( arr.length == 2 ){
		return arr[1]+' '+arr[0];
	}
	arr.sort(function(a,b){
		return a-b;		//真正的排序方式
	});	
	var max = arr.pop();
	var min = arr.shift();
	var result = new String();
	if( arr.length == 1)
		return arr+' '+arr;
	var second =[0,0];
	//常规思路..
	for( i = 0;i < arr.length; i++){
		if( min == arr[i] )
			continue;
		second[0] = arr[i];
		break;
	}
	for( i = arr.length - 1; i > 0;i --){
		if( max == arr[i] )
			continue;
		second[1] = arr[i];
		break;
	}
	return second.join(' ');
}
var arr  = [1,2,32,80,80];
SecondGreatLow( arr );