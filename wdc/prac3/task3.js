function updateMouseCount()
{
	var p=0;
	p=p+1;
   document.getElementById("mcount").innerHTML=p;
}
function addPost()
{
var input=document.getElementById("txt").value;
var text=document.getElementById("posts");
text.value= input;
text.innerHTML=Date()+"\n"+text;



}

