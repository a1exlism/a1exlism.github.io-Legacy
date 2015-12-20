/*---------About : Array() ------------
function:
1. Array.slice(begin[,end])截取
2. Array.unshift();	出队列
3. return [arr];	//返回数组的详细信息,包括length和proto
4. splice();需要重新认识!
var arr1 = ['a','b','c','d','e'];
var arr2 = arr1.splice( 0 );
arr2.shift( 0 );
console.log( arr2 );
console.log( arr1 );
unshift( 'a' );
console.log( arr2 );
//返回[]空对象
*/


/*2015-11-18下次再看几遍*/
function getPermutation( arr ){
	if ( arr.length == 1 ){
		return [arr];
	}
	var permutation = [];
	for( var i = 0; i < arr.length; i++ ){		//以头元素为循环内进行for循环
		var firstEle = arr[i];
		
		var arrClone = arr.slice( 0 );	//slice表示选取整段数组,并完全转移,此时arr=[]
		
		arrClone.splice( i ,1 );	//变幻元素

		var childPermutation = getPermutation( arrClone );

		for( var j = 0; j < childPermutation.length; j ++){	//去掉首元素
		
			childPermutation[j].unshift( firstEle );	
		}
		permutation = permutation.concat( childPermutation );	//元素连接
	}	
	return permutation;
}
var permutation = getPermutation( ['a','b','c']);
console.dir( permutation );