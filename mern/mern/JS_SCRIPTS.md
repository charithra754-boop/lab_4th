# JavaScript-only Scripts from MERN Examples

This file collects all JavaScript-only scripts from the `mern/mern` examples, ordered by question number.

## 1. Question 1 — `1_profile.html`
```js
const nameEl = document.getElementById('name');
const bioEl = document.getElementById('bio');
const picEl = document.getElementById('pic');
const updateBtn = document.getElementById('updateBtn');
updateBtn.addEventListener('click', updateProfile);
function updateProfile() {
    nameEl.innerText = "Jane Smith";
    bioEl.innerText = "Web Designer";
    picEl.src = "https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=150";
}
```

## 2. Question 2 — `2_calculator.html`
```js
const input = document.getElementById('i');
const calc = document.getElementById('calc');
calc.addEventListener('click', function(event) {
    const t = event.target;
    if (t.tagName !== 'BUTTON') return;

    const value = t.innerText;
    if (value === 'C') {
        input.value = '';
    } else if (value === '=') {
        try {
            input.value = input.value ? eval(input.value) : '';
        } catch {
            input.value = 'Error';
        }
    } else {
        input.value += value;
    }
});
```

## 3. Question 4 — `4_registration.html`
```js
const regForm = document.getElementById('regForm');
const msg = document.getElementById('msg');
regForm.addEventListener('submit', function(event) {
    event.preventDefault();
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const phone = document.getElementById('phone').value;
    msg.innerText = `Registered ${name} (${email}, ${phone})`;
});
```

## 4. Question 5 — `5_animation.html`
```js
let isLarge = false;
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
const passInput = document.getElementById('pass');
const strength = document.getElementById('strength');
passInput.addEventListener('input', check);

function check() {
    const p = passInput.value;
    const regex = /^(?=.*[a-zA-Z])(?=.*[0-9]).{8,}$/;

    if (p.length === 0) {
        strength.innerText = "";
    } else if (regex.test(p)) {
        strength.innerText = "Strong (Alphanumeric + 8 chars)";
        strength.style.color = "green";
    } else {
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
    const [input, setInput] = React.useState('');

    function handleClick(value) {
        if (value === 'C') {
            setInput('');
        } else if (value === '=') {
            try {
                setInput(input ? String(eval(input)) : '');
            } catch {
                setInput('Error');
            }
        } else {
            setInput(input + value);
        }
    }

    return (
        <div className="calc">
            <input value={input} readOnly />
            <button onClick={() => handleClick('7')}>7</button>
            <button onClick={() => handleClick('8')}>8</button>
            <button onClick={() => handleClick('9')}>9</button>
            <button className="op" onClick={() => handleClick('/')}>/</button>

            <button onClick={() => handleClick('4')}>4</button>
            <button onClick={() => handleClick('5')}>5</button>
            <button onClick={() => handleClick('6')}>6</button>
            <button className="op" onClick={() => handleClick('*')}>*</button>

            <button onClick={() => handleClick('1')}>1</button>
            <button onClick={() => handleClick('2')}>2</button>
            <button onClick={() => handleClick('3')}>3</button>
            <button className="op" onClick={() => handleClick('-')}>-</button>

            <button className="op" onClick={() => handleClick('C')}>C</button>
            <button onClick={() => handleClick('0')}>0</button>
            <button className="op" onClick={() => handleClick('=')}>=</button>
            <button className="op" onClick={() => handleClick('+')}>+</button>
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
