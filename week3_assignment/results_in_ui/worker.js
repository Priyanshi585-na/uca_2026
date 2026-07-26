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

		self.postMessage({
			success: true,
			users: user
		});

	} catch(error){
		self.postMessage({
			success: false,
			message: error.message
		});
	}

};
