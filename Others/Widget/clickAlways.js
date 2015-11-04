//---sites:https://my1111.tmall.com/------
设置需要点击的地方
id="click1111"

var click1 = document.getElementById('click1111');
click1.onclick = function(){
	setInterval(function(){
		click1.click();
	},1500);
}