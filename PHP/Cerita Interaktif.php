<?php
// Mulai sesi untuk menyimpan status cerita
session_start();

// Inisialisasi cerita jika belum ada
if (!isset($_SESSION['step'])) {
    $_SESSION['step'] = 1;
}

// Fungsi untuk menampilkan cerita berdasarkan langkah
function getStory($step) {
    $stories = [
        1 => [
            'text' => "Kamu sedang berjalan di hutan misterius. Tiba-tiba, kamu menemukan sebuah cabang jalan. Kiri menuju sungai, kanan menuju gua gelap. Apa yang kamu pilih?",
            'options' => [
                'kiri' => 'Pergi ke sungai',
                'kanan' => 'Masuk ke gua'
            ]
        ],
        2 => [
            'text' => "Di sungai, kamu menemukan seekor ikan ajaib yang bisa berbicara! Ia menawarkan hadiah: kekuatan super atau peta harta karun. Mana yang kamu ambil?",
            'options' => [
                'kekuatan' => 'Ambil kekuatan super',
                'peta' => 'Ambil peta harta karun'
            ]
        ],
        3 => [
            'text' => "Di gua, kamu menemukan naga tidur! Kamu bisa mencuri emasnya atau membangunkannya untuk bertarung. Apa yang kamu lakukan?",
            'options' => [
                'curi' => 'Curi emasnya diam-diam',
                'bangun' => 'Bangunkan naga untuk bertarung'
            ]
        ],
        // Akhir cerita berdasarkan pilihan
        4 => [
            'text' => "Dengan kekuatan super, kamu menyelamatkan desa dari monster! Kamu adalah pahlawan. Akhir bahagia!",
            'options' => []
        ],
        5 => [
            'text' => "Peta harta karun membawa kamu ke pulau terpencil. Kamu kaya raya, tapi sendirian. Akhir netral.",
            'options' => []
        ],
        6 => [
            'text' => "Kamu berhasil mencuri emas tanpa terdeteksi! Kamu kaya, tapi naga mungkin memburu kamu. Akhir misterius.",
            'options' => []
        ],
        7 => [
            'text' => "Naga bangun dan membakar kamu! Kamu kalah. Akhir tragis.",
            'options' => []
        ]
    ];
    return $stories[$step] ?? ['text' => 'Cerita selesai.', 'options' => []];
}

// Proses pilihan pengguna
if (isset($_POST['choice'])) {
    $choice = $_POST['choice'];
    if ($_SESSION['step'] == 1) {
        $_SESSION['step'] = ($choice == 'kiri') ? 2 : 3;
    } elseif ($_SESSION['step'] == 2) {
        $_SESSION['step'] = ($choice == 'kekuatan') ? 4 : 5;
    } elseif ($_SESSION['step'] == 3) {
        $_SESSION['step'] = ($choice == 'curi') ? 6 : 7;
    }
}

// Ambil cerita saat ini
$currentStory = getStory($_SESSION['step']);
?>

<!DOCTYPE html>
<html lang="id">

<head>
    <meta charset="UTF-8">
    <title>Cerita Interaktif: Petualangan di Hutan Misterius</title>
    <style>
    body {
        font-family: Arial, sans-serif;
        margin: 20px;
        background-color: #f0f0f0;
    }

    .story {
        background: white;
        padding: 20px;
        border-radius: 10px;
        box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    }

    button {
        margin: 5px;
        padding: 10px 20px;
        background: #4CAF50;
        color: white;
        border: none;
        border-radius: 5px;
        cursor: pointer;
    }

    button:hover {
        background: #45a049;
    }
    </style>
</head>

<body>
    <h1>Petualangan di Hutan Misterius</h1>
    <div class="story">
        <p><?php echo $currentStory['text']; ?></p>
        <?php if (!empty($currentStory['options'])): ?>
        <form method="post">
            <?php foreach ($currentStory['options'] as $key => $option): ?>
            <button type="submit" name="choice" value="<?php echo $key; ?>"><?php echo $option; ?></button>
            <?php endforeach; ?>
        </form>
        <?php else: ?>
        <p><a href="?reset=1">Mulai Ulang Cerita</a></p>
        <?php endif; ?>
    </div>
    <?php
    // Reset cerita jika diminta
    if (isset($_GET['reset'])) {
        session_destroy();
        header("Location: " . $_SERVER['PHP_SELF']);
        exit;
    }
    ?>
</body>

</html>