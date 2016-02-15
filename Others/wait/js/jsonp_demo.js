/*-------------------
http://kb.cnblogs.com/page/139725/
http://my.oschina.net/u/874424/blog/280417
-------------------*/
------本质-------
客户端中定义回调函数(callback),服务器端置入json对象并调用该回调函数(callback)
服务器端:
	将JSON数据包装为js函数,将一个对象作为参数放入函数
originJSON:
{
	'flightId': 'CA1998',
	'price': 2000
}
--------------Jquery-jsonp---------------
jQuery(document).ready(function($) {
	$.ajax({
		type: 'GET',
		async: false,
		url: 'http://chong.qq.com/php/index.php?d=active&c=activeV3&m=index&activeId=ppms_app_domore&promoteId=ppms_app&callback=callback&returnType=jsonp&g_tk=',
		dataType: 'jsonp',
		jsonp: 'callback',
		jsonpCallback: 'callback',	//callback函数名
		success: function(data){
			alert( data.msg );	//json数据内容
		},
		error: function( error ){
			alert( error );
		}
	})
});
---------------JavaScript-jsonp-----------------

function jsonp( options ){
	options = options || {};
	if( !options.url || !options.callback ){
		throw new Error('参数不合法');
	}
	//-----添加Script标签----
	var callbackName = ('jsonp_' + Math.random()).replace('.','');
	var oHead = document.getElementsByTagName('head')[0];
	options.data[options.callback] = callbackName;	//暂时不懂
	var params = formatParams(options.data);
	var oS = document.createElement('script');
	oHead.append(oS);
	
	//-----创建回调函数-----
	window[callbackName] = function (json){
		oHead.removeChild(oS);
		clearTimeout(oS.timer);
		window[callbackName] = null;
		options.success && options.success(json);
	};
	//-----发送请求-----
	oS.src = options.url + '?' + params;

	//-----超时处理-----
	if( options.time ){
		oS.timer = setTimeout(function(){
			window[callbackName] = null;
			oHead.removeChild(oS);
			options.fail && options.fail({
				message: "超时"
			},time);
		})
	}
}
function formatParams( data ){		//参数格式化
	var arr = [];
	for( var name in data ){	//name 遍历下标
		arr.push( encodeURIComponent( name ) + '=' + encodeURIComponent(data[name]));
	}
	var tvalue = Math.random().toString().substring(2);
	arr.push('v=' + tvalue);	//拒绝浏览器缓存
	return arr.join('&');
}

ajax({
	url: "http://chong.qq.com/php/index.php?d=active&c=activeV3&m=index&activeId=ppms_app_domore&promoteId=ppms_app&callback=callback&returnType=jsonp&g_tk=",
	type: "GET",
	// data :	请求参数
	dataType: "json",
	success: function(response, xml){
		alert( response );
	},
	fail: function( error ){
		alert( error );
	}
});
