const worker = new Worker("worker.js");

const usersDiv = document.getElementById("users");

worker.onmessage = function(event) {

    if (event.data.success) {

        event.data.users.forEach(user => {

            const p = document.createElement("p");
            p.textContent = `${user.name} - Active: ${user.active}`;

            usersDiv.appendChild(p);

        });

    } else {

        usersDiv.textContent = event.data.message;

    }
};

worker.onerror = function(error) {
    console.error(error);
};

worker.postMessage("users.json");


