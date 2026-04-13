// Simple Express static server for local development
const express = require('express');
const path = require('node:path');
const app = express();
const port = process.env.PORT || 3000;

// Serve static files from the current directory (where index.html is)
app.use(express.static(path.join(__dirname, '/')));

app.get('/', (req, res) => {
  res.sendFile(path.join(__dirname, 'index.html'));
});

app.listen(port, () => {
  console.log(`Calculator app available at http://localhost:${port}`);
});