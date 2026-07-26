self.onmessage = async function(event)
{
	try{
		const response = await fetch(event.data);

		if(!response.ok)
		{
			throw new Error("Failed to fetch.");
		}

		const user = await response.json();

		if(!user.length)
		{
			throw new Error("No users returned from the API");
		}

		user.forEach(user => {
			console.log(`${user.name} - Active: ${user.active}`);
		});

		self.postMessage("User details displayed successfully");
	} catch(error){
		self.postMessage(`Error: ${error.message}`);
	}

};
