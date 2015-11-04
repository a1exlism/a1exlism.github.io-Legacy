//---sites:https://my1111.tmall.com/------
设置需要点击的地方
id="click1111"

//---------Version 2---------
//issue:解决了因为递归而产生的性能问题,自己太傻= =--------------
//更改后就能随便设置时间了..默认0.5s抢 可以自行设置
var click1 = document.getElementById('click1111');
setInterval(function(){
		click1.click();
	},500);
//---------Version 1---------
var click1 = document.getElementById('click1111');
click1.onclick = function(){
	setInterval(function(){
		click1.click();
	},1500);
}