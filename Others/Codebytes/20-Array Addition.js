function ArrayAddition(arr) { 
	var max = arr[0];
	for( var i = 1; i < arr.length ;i++){
		if( max < arr[i] )
			max = arr[i];
	}
	//------最笨的办法---------
	var maxcp = max;	//exclude max value
	for( var i = 0; i < arr.length; i++){
		if( arr[i] == maxcp )
			continue;
		
	}
	// code goes here  
	return arr; 
	       
}