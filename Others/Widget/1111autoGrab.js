click1 = document.getElementById('J_LotteryBTN');
click1.onclick = function(){
var mask = document.getElementsByClassName('ui-mask')[0];
var removeEle = function(node){
	node.parentNode.removeChild(node);
}
setTimeout(function(){
	removeEle(mask);
},500);
// var click2 = document.querySelector('a[target="_self"]');
// setTimeout(function() { click2.click(); }, 10000);
setInterval( function(){
		click1.click();
		removeEle(document.getElementsByClassName('ui-mask')[0]);
		//click2.click();
	},10000);
};

//--------bug待会儿修复-------