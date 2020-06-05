function addPost()
{
var input=document.getElementById("txt").value;
var text=document.getElementById("posts");
text.value= input;
text.innerHTML=Date()+"\n"+text;
}

