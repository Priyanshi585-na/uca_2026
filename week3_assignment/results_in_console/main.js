const worker = new Worker("worker.js");

worker.onmessage = function (event)
{
	console.log(event.data);
};

worker.onerror = function(error)
{
	console.log("Worker Error:", error);
};

worker.postMessage("users.json");

