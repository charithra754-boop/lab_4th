# JavaScript-only Scripts from MERN Examples

This file collects all JavaScript-only scripts from the `mern/mern` examples, ordered by question number.

## 1. Question 1 — `1_profile.html`
```js
// find the name element by its ID
const nameEl = document.getElementById('name');
// find the bio paragraph by its ID
const bioEl = document.getElementById('bio');
// find the profile picture image by its ID
const picEl = document.getElementById('pic');
// find the update button by its ID
const updateBtn = document.getElementById('updateBtn');

// attach a click listener to the button
updateBtn.addEventListener('click', updateProfile);

// function that runs when the button is clicked
function updateProfile() {
    // change the text inside the name heading
    nameEl.innerText = "Jane Smith";
    // change the text inside the bio paragraph
    bioEl.innerText = "Web Designer";
    // change the image source to a new picture
    picEl.src = "https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=150";
}
```

## 2. Question 2 — `2_calculator.html`
```js
// select the calculator display input by ID
const input = document.getElementById('i');
// select the container holding the calculator buttons
const calc = document.getElementById('calc');

// listen for clicks inside the calculator container
calc.addEventListener('click', function(event) {
    const t = event.target;
    // ignore clicks that are not on buttons
    if (t.tagName !== 'BUTTON') return;

    const value = t.innerText;
    if (value === 'C') {
        // clear the display when C is clicked
        input.value = '';
    } else if (value === '=') {
        // evaluate the expression when = is clicked
        try {
            input.value = input.value ? eval(input.value) : '';
        } catch {
            // show Error for invalid expressions
            input.value = 'Error';
        }
    } else {
        // append the clicked button text to the display
        input.value += value;
    }
});
```

## 3. Question 4 — `4_registration.html`
```js
// find the form element by ID
const regForm = document.getElementById('regForm');
// find the message paragraph by ID
const msg = document.getElementById('msg');

// listen for the form submit event
regForm.addEventListener('submit', function(event) {
    // stop the browser from sending the form to the server
    event.preventDefault();

    // read the values entered by the user
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const phone = document.getElementById('phone').value;

    // show a confirmation message without reloading the page
    msg.innerText = `Registered ${name} (${email}, ${phone})`;
});
```

## 4. Question 5 — `5_animation.html`
```js
let isLarge = false;

// Automatically runs the loop every 1500 milliseconds (1.5 seconds)
setInterval(() => {
    if (!isLarge) {
        text.style.fontSize = "50px";
        text.style.color = "red";
        text.innerText = "ENLARGED";
    } else {
        text.style.fontSize = "20px";
        text.style.color = "blue";
        text.innerText = "SHRUNK";
    }
    isLarge = !isLarge;
}, 1500);
```

## 5. Question 6 — `6_password.html`
```js
// find the password input field by ID
const passInput = document.getElementById('pass');
// find the strength label by ID
const strength = document.getElementById('strength');

// run the check function each time the input value changes
passInput.addEventListener('input', check);

function check() {
    // read the current password value
    const p = passInput.value;
    // define the rule: letters + numbers + at least 8 chars
    const regex = /^(?=.*[a-zA-Z])(?=.*[0-9]).{8,}$/;

    if (p.length === 0) {
        // if the input is empty, show nothing
        strength.innerText = "";
    } else if (regex.test(p)) {
        // if password matches the rule, show strong
        strength.innerText = "Strong (Alphanumeric + 8 chars)";
        strength.style.color = "green";
    } else {
        // otherwise show weak and make it red
        strength.innerText = "Weak (Need Letter, Number & 8+ length)";
        strength.style.color = "red";
    }
}
```

## 6. Question 7 — `7_star_rating.html`
```js
$(document).ready(function(){
    $(".star").click(function(){
        let v = $(this).data("v");
        $(".star").removeClass("selected");
        $(".star").each(function(){
            if($(this).data("v") <= v) $(this).addClass("selected");
        });
    });
});
```

## 7. Question 8 — `8_react_name.html`
```jsx
function App() {
    const [name, setName] = React.useState("");
    const date = new Date().toDateString();
    return (
        <div style={{textAlign: "center"}}>
            <h1>Date: {date}</h1>
            <input type="text" placeholder="Enter Name" onChange={(e)=>setName(e.target.value)} />
            <h2>Hello, {name}</h2>
        </div>
    );
}
ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```

## 8. Question 9 — `9_react_calc.html`
```jsx
function App() {
    const [a, setA] = React.useState(0);
    const [b, setB] = React.useState(0);
    const [res, setRes] = React.useState(0);
    return (
        <div style={{textAlign: "center"}}>
            <h2>React Calculator</h2>
            <input type="number" onChange={(e)=>setA(Number(e.target.value))} />
            <input type="number" onChange={(e)=>setB(Number(e.target.value))} /><br/>
            <button onClick={()=>setRes(a+b)}>+</button>
            <button onClick={()=>setRes(a-b)}>-</button>
            <button onClick={()=>setRes(a*b)}>*</button>
            <button onClick={()=>setRes(a/b)}>/</button>
            <h3>Result: {res}</h3>
        </div>
    );
}
ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```

## 9. Question 10 — `10_react_voting.html`
```jsx
function App() {
    const [v1, setV1] = React.useState(0);
    const [v2, setV2] = React.useState(0);
    return (
        <div style={{textAlign: "center"}}>
            <h2>Voting App</h2>
            <button onClick={()=>setV1(v1+1)}>Vote A</button> Count: {v1}<br/>
            <button onClick={()=>setV2(v2+1)}>Vote B</button> Count: {v2}
        </div>
    );
}
ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```

## 10. Question 11 — `11_react_toggle.html`
```jsx
function App() {
    const [on, setOn] = React.useState(true);
    return (
        <div style={{textAlign: "center"}}>
            <button onClick={()=>setOn(!on)}>{on ? "ON" : "OFF"}</button>
        </div>
    );
}
ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```

## 11. Question 12 — `12_react_counter.html`
```jsx
function App() {
    const [count, setCount] = React.useState(0);
    return (
        <div style={{textAlign: "center"}}>
            <h1>Counter: {count}</h1>
            <button onClick={()=>setCount(count+1)}>Inc</button>
            <button onClick={()=>setCount(count-1)}>Dec</button>
        </div>
    );
}
ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```

> Note: `3_timetable.html` has no JavaScript script block.
