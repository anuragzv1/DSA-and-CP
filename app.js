
//run the app using -->>>   node app **value of N here **
//If no value of N is passed as arguments, default will be taken as 2;

var min = "1";
var max = "9";
var i = 0;


var n;
if (typeof (process.argv[2])==undefined) {      //taking in the value of N from the arguments
    n = 2;
}
else n = process.argv[2];

for (i = 1; i < n; i++) {    //calculating range of numbers
    min += "0";
    max += "9";
}


for (i = min; i <= max; i++) {      //checking if the numbers satisfy the given condition
    if (i % 6 == 0) console.log(i);
}