var express = require('express');
var router = express.Router();

var fs=require('fs');


var users = {};

var sessions = {};

router.post('/user.json', function(req, res) {
    
    var user = null;
    
    console.log(JSON.stringify(req.body));
    
    // If login details present, attempt login
    if(req.body.username !== undefined && req.body.password !== undefined){
        console.log("Username + Password received");
        // If user does not exist, add them
        if(users[req.body.username] === undefined ){
            users[req.body.username] = {password:req.body.password};
            console.log("Added User");
        // Otherwise log them in
        } else {
            if(users[req.body.username].password === req.body.password){
                sessions[req.session.id] = req.body.username;
                user = req.body.username;
            }
        }
    // If no login details, but valid session
    } else if(sessions[req.session.id] !== undefined) {
        console.log("Valid session");
        user = sessions[req.session.id];
    }
    
    res.json({username:user});
    
});

router.get('/posts.json',function(req,res){
fs.readFile('/usaccount.json','utf8',function(err,data){
   usaccount =JSON.parse(data);
});
});

module.exports = router;
