var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var session = require('express-session');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var app = express();
app.listen(3000);
// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
app.use(session({secret: 'secret', resave: true, saveUninitialized: true }));
app.get('/public/login',function(req,res){
res.sendFile(__dirname+'/public/login.html')
});
app.post('/account',function(req,res){
if(req.body.username==undefined &&req.body.pwd ==undefined){
req.session.userName=req.body.username;
res.redirect('/');
}else{
res.json({ret_code: 1,ret_msg:"wrong pwd or name"});
}
});
app.get('/',function(req,res){
if(req.session.userName){
res.render('login',{username: req.session.userName});
}else{
res.redirect('login');
}
})
app.get('/logout',function(req,res){
req.session.userName=null;
res.redirect('login');
});
app.use('/', indexRouter);
app.use('/users', usersRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
