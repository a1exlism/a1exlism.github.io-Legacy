//site: https://www.tmall.com/wow/act/14700/huabei-hdc1111
//--------Version 4----------------
//issue:解决了和另一个脚本一样由递归导致的致命错误---
var click1 = document.getElementById('J_LotteryBTN');
var closeBtn = document.getElementsByClassName('ui-button-yl J_Close');
setInterval( function(){
	click1.click();
	setTimeout(function(){
		if(closeBtn[0])
			closeBtn[0].click();
	},50);
},7500);			//肉眼查看了更新时间发现7.5s刚刚好2333

//----------testCode:--------
var a = document.getElementsByClassName('ui-button-yl J_Close');
for(var i = 0;i < a.length;)
	console.log(a[i++]);
//--------Version 3----------------
//issue:-----修复一直报错的问题----
//Q:虽然没有报错的问题了,但是脚本一段时间之后就会死..不知道什么原因..
var click1 = document.getElementById('J_LotteryBTN');
click1.onclick = function(){
var closeBtn = document.getElementsByClassName('ui-button-yl J_Close')[0];
setTimeout(function(){
	if(closeBtn)
		closeBtn.click();
},12000);
setInterval( function(){
		if(closeBtn)
		closeBtn.click();
		click1.click();
	},10000);
};

//--------Version 2----------------
//issue:-------失败后的<a>标签classname唯一,遂简化-----

var click1 = document.getElementById('J_LotteryBTN');
click1.onclick = function(){
setTimeout(function(){
	document.getElementsByClassName('ui-button-yl J_Close')[0].click();
},12000);
setInterval( function(){
		click1.click();
		document.getElementsByClassName('ui-button-yl J_Close')[0].click();
	},10000);
};

//-------Version 1----------
var mask = document.getElementsByClassName('ui-mask')[0];
var removeEle = function(node){
	if (node.parentNode)
		node.parentNode.removeChild(node);
}	//删除节点
setTimeout(function(){		//presume first failed
	removeEle(mask);
},500);
</a>