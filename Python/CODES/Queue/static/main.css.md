# CSS code for rendering templates

<strong>NOTE</strong>: CSS defines the customized styles for display of template files when rendered by Flask application. We have restricted
use of CSS to a minimum and rely on bootstrap styles available through CDN. The apporach makes it simple to build Flask web applications 
quickly without knowing all the details of HTML, Java Scripts, CSS and Jinja template engine.


```
*,
*:before,
*:after {
  box-sizing: border-box;
}

pre[class*="language-"] {
  position: relative;
  overflow: auto;
  background-color:#220322;
  color: white;
  width: 95%;
  /* make space  */
  margin: 5px 0;
  padding: 1.75rem 0 1.75rem 1rem;
  border-radius: 10px;
}

pre[class*="language-"] button {
  position: absolute;
  top: 15px;
  right: 5px;

  font-size: 0.9rem;
  padding: 0.15rem;
  background-color: #828282;

  border: ridge 1px #7b7b7c;
  border-radius: 5px;
  text-shadow: #c4c4c4 0 0 2px;
}

pre[class*="language-"] button:hover {
  cursor: pointer;
  background-color: #bcbabb;
}
code[class*="language-"] {
white-space: pre-wrap;
word-break: break-all;
}

pre[class*="plain"] {
display:block;
padding:9.5px;
font-size:87.5%;
color:#212529
}
```
