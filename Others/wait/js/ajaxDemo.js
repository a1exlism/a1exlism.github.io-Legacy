//----------demo|MDN---------
var http_request = false;
function makeRequest( url ){
	if(window.XMLHttpRequest){
		http_request = new XMLHttpRequest;
		if(http_request.overrideMimeType){
			http_request.overrideMimeType('text/xml');
		}
	}else if(window.ActiveXObject){
		try{
			http_request = new ActiveXObject("Microsof.XMLHTTP");
		}catch( e ){}
	}
	if( !http_request ){		//不存在http_request对象
		alert( 'Failed create XMLHttpRequestObject');
		return false;
	}
	http_request.onreadystatechange = alertContents;	//httpStatus状态改变时出发alertContets();
	http_request.open('GET',url,true);
	http_request.send(null);
	function alertContents(){
		if(http_request.readyState == 4){
			if( http_request.status == 200){
				alert(http_request.reponseText);
			}else{
				alert('connect error');
			}
		}
	}
}

//------XML数据-------
makeRequest('test.xml');
var xmldoc = http_request.reponseXML;
var root_node = xmldoc.getElementsByTagName('root').item(0);
alert(root_node.firstChild.data);






//-------创建xmlHttpRequest对象---------
function createXmlHttpRequest() {
	if (window.XMLHttpRequest) { // Mozilla, Safari, ...
		http_request = new XMLHttpRequest();
	} else if (window.ActiveXObject) { // IE
		http_request = new ActiveXObject("Microsoft.XMLHTTP");
	}
}
http_request = new XMLHttpRequest();
http_request.overrideMimeType('text/xml');	//保证正确解析
// http_request.onreadystatechange = nameOfTheFunction;
//自定义状态改变后的函数

//--------客户端请求---------
http_request.open('GET','http://requestedURL.com',true);	//true 异步调用
http_request.send(null);

//---------服务器响应----------
if(http_request.status == 200){
	//when get normal
}else{
	//problem
}
http_request.responseText	//字符串形式返回服务器响应
http_request.reponseXML	//XMLDocument对象返回响应

//----------readyState------
//	https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/readyState
var xhr = new XMLHttpRequest();
console.log('Unsent',xhr.readyState);
xhr.open('GET','./url',true);
console.log('Opened',xhr.readyState);
xhr.onprogress = function(){
	console.log('Loading',xhr.readyState);
}
xhr.onload = function(){
	console.log('Done',xhr.readyState);
}
xhr.send(null);

//----------MonitorProgress/事件监听---------
-------出现原因------
document.getElementById("btn").onclick = method1; 
document.getElementById("btn").onclick = method2; 
document.getElementById("btn").onclick = method3; 
//只会执行method3
btn1Obj.addEventListener("click",method1,false); 
btn1Obj.addEventListener("click",method2,false); 
btn1Obj.addEventListener("click",method3,false); 
//执行method1->2>3
--------Demo--------
var oReq = new XMLHttpRequest();
oReq.addEvenetListener('progress', updateProgress);	//监听oReq进度事件
oReq.addEvenetListener('load', transferComplete);	//成功加载
oReq.addEvenetListener('error', transferFailed);	//加载失败
oReq.addEvenetListener('abort', transferCanceled);	//加载终止
oReq.open();
function updateProgress( oEvent ){
	if( oEvent.lengthComputable ){
		var percentComplete = oEvent.loaded / oEvent.total;
	}else{
		//
	}
}
function transferComplete( evt ){
	console.log('Ther transfer is complete.');
}
......
loadend == (abort, load, or error)	//loadend事件
