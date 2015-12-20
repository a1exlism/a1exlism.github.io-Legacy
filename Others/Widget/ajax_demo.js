1. creat Httprequest


if( window.XMLHttpRequest){
	httpRequest = new XMLHttpRequest();
}else if( window.ActiveXObject){
	httpRequest = new ActiveXObject("Microsoft.XMLHTTP");
}
httpRequest.onreadystatechange = function(){
	//process the sercer response
}	//httpstatus改变时的函数
httpRequest.open('GET', 'https://google.com',true );
//Method:  GET, POST, HEAD
httpRequest.send( null );
//The parameter to the send() method can be any data you want to send to the server 
//if POST-ing the request.
//include JSON,SOAP,etc 
2. Handling the server response


httpRequest.onreadystatechange = nameOfTheFunction;
/*
check for the state of the request
*/
if ( httpRequest.readyState === XMLHttpRequest.DONE){
	//Got the response
}else{
	//not ready
}
/*
httpRequest.readyState Contains:
0 (uninitialized)
1 (loading)
2 (loaded)
3 (interactive)
4 (complete)
*/
if( httpRequest.status === 200 ){
	// Run well
}else{
	//occur some problems
}

3. Example


<span id="ajaxButton" style="cursor: pointer;text-decoration: underline">
 Make a request
</span>
<script type="text/javascript">
(function(){
	var httpRequest;
	document.getElementById("ajaxButton").onclick = function(){
		makeRequest('test.html');
	}
	function makeRequest( url ){
		httpRequest = new XMLHttpRequest();
		if( !httpRequest ){
			alert( "Cann't create XMLHTTP");
			return false;
		}
		httpRequest.onreadystatechange = alertContents;	//收到服务器响应之后的function
		httpRequest.open('GET', url);
		httpRequest.send();
	}
	function alertContents(){
		//XMLHttpRequest.DONE === 4状态码
		if( httpRequest.readyState === XMLHttpRequest.DONE ){
			if( httpRequest.status === 200 ){
				alert( httpRequest.responseText );
			}else{
				alert( 'Request Problem ');
			}	
		}
	}
})();			//闭包
</script>

//-----------
(function(){
  //去看看js科学与艺术
})();
//------------

4. //try语句
function alertContents(){
	try{
		if( httpRequest.readyState === XMLHttpRequest.DONE ){
			if( httpRequest.status === 200 ){
				alert( httpRequest.responseText );
			}else{
				alert( 'Problem Request ');
			}
		}
	}
	catch( e ){
		alert( 'Caought Exception : '+ e.description );	//报错机制
	}
}
5. XML response
function alertContents(){
	try{
		if( httpRequest.readyState === XMLHttpRequest.DONE ){
			if( httpRequest.status	=== 200 ){
				var xmldoc = httpRequest.responseXML;
				var root_node = xmldoc.getElementsByTagName('root').item(0);
				alert( root_node.firstChild.data );
			}
		}else{
			alert( 'Request Problem.');
		}
	}
}
6. data interaction
<label>Your name: 
 <input type="text" id="ajaxTextBox">
<label>
<span id="ajaxButton" style="cursor: pointer; text-decoration: underline">
 Make request
</span>
<script>
	document.getElementById('ajaxButton').onclick = function(){
		var userName = document.getElementById(' ajaxTextBox').value;
		makeRequest('test.php', userName );
	};
	function makeRequest(url , val){
		httpRequest.onreadystatechange = alertContents;
		httpRequest.open('POST', url);
		httpRequest.setReqestHeader('Content-Type','applictation/x-www-form-urlencoded');
		//创建Http header
		httpRequest.send('userName=' + encodeURIComponent(userName));
	}
	//if type 'Jane'	
	//server's request format may :
	//{"userData":"Jane","computedString":"Hi, Jane!"}
	function alertContents(){
		//code
	}
</script>
</label></label>