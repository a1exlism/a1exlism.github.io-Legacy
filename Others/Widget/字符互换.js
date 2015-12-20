//abcdefghijklmnopqrstuvwxyz=>
//pvwdgazxubqfsnrhocitlkeymj

var str = 'Wxgcg txgcg ui p ixgff, txgcg ui p epm. I gyhgwt mrl lig txg ixgff wrsspnd tr irfkg txui hcrvfgs, nre, hfgpig tcm liunz txg crt13 ra "ixgff" tr gntgc ngyt fgkgf.'
var a = 'pvwdgazxubqfsnrhocitlkeymj';
var b = 'abcdefghijklmnopqrstuvwxyz';
var newstr = '';
for( var i = 0; i < str.length; i++){
	if( str[i].match(/[^a-z]/i) ){
		newstr += str[i];
	}else{
		if( str[i].match(/[A-Z]/) )	//大小写
			newstr += b[a.indexOf(str[i].toLowerCase())].toUpperCase();
		else
			newstr += b[a.indexOf(str[i])];
	}
}
console.log( newstr );
