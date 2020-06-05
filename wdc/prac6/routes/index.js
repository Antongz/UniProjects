var express = require('express');
var router = express.Router();
var fs=require('fs');
var blog=[];
var title=[];
var text=[];
var li="";


/* GET home page. */
router.get('/log.html',function(req,res){
var text=Date();
li +='<li>'+text+'</li>';
res.send('<!DOCTYPE html>\
<html>\
 <head>\
 <title>MY Page</title>\
</head>\
<body>\
<ul>'+li+'</ul>\
</body>\
</html>');
});

router.get('/posts.json',function(req,res){
fs.readFile('data/blog.json','utf8',function(err,data){
    blog=JSON.parse(data);
});
res.send('<!DOCTYPE html>\
<html>\
 <head>\
 <title>title</title>\
</head>\
<body>\
<p>text</p>\
</body>\
</html>');
});

module.exports = router;


