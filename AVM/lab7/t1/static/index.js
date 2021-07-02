'use strict';

window.onload = function() {
    const add_field_btn = document.getElementById('add-field-id');
    const v_list = document.getElementById('v-list');
    add_field_btn.onclick = function() {
        const i = v_list.childElementCount;
        const str = `<p>Машина ${i+1}: <input type="text" name="v_${i}" spellcheck="false" autocomplete="off"></p>\n`
        const temp = document.createElement('div');
        temp.innerHTML = str;
        while (temp.firstChild) {
            v_list.appendChild(temp.firstChild);
        }
    };
};
