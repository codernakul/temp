const base64map = {
    "0": "A",
    "1": "B",
    "2": "C",
    "3": "D",
    "4": "E",
    "5": "F",
    "6": "G",
    "7": "H",
    "8": "I",
    "9": "J",
    "10": "K",
    "11": "L",
    "12": "M",
    "13": "N",
    "14": "O",
    "15": "P",
    "16": "Q",
    "17": "R",
    "18": "S",
    "19": "T",
    "20": "U",
    "21": "V",
    "22": "W",
    "23": "X",
    "24": "Y",
    "25": "Z",
    "26": "a",
    "27": "b",
    "28": "c",
    "29": "d",
    "30": "e",
    "31": "f",
    "32": "g",
    "33": "h",
    "34": "i",
    "35": "j",
    "36": "k",
    "37": "l",
    "38": "m",
    "39": "n",
    "40": "o",
    "41": "p",
    "42": "q",
    "43": "r",
    "44": "s",
    "45": "t",
    "46": "u",
    "47": "v",
    "48": "w",
    "49": "x",
    "50": "y",
    "51": "z",
    "52": "0",
    "53": "1",
    "54": "2",
    "55": "3",
    "56": "4",
    "57": "5",
    "58": "6",
    "59": "7",
    "60": "8",
    "61": "9",
    "62": "+",
    "63": "/"
}

const queryString = window.location.search;
const urlParams = new URLSearchParams(queryString);
const str = urlParams.get('str');

function conv(s) {
    let bin = "";

    for (let i = 0; i < s.length; i++) {
        bin = bin + s.charCodeAt(i).toString(2).padStart(8, '0');
    }

    let sixByte, sixBytePadded, base64 = "";
    while (bin.length != 0) {
        sixByte = bin.substring(0, 6)
        if (sixByte.length < 6)
            sixByte = sixByte.padEnd(6, '0')
        sixBytePadded = sixByte.padStart(8, '0');
        base64 = base64 + base64map[parseInt(sixBytePadded, 2).toString(10)];
        bin = bin.substring(6);
    }
    return base64;
}

document.getElementById("Answer").innerHTML = conv(str);

// const jsonResponse = Response.json({ my: conv(str) });
// logResponse(jsonResponse);