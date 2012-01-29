<?php
/**
 * @file
 * Override of the maintenance-page template file
 */
?>

<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
<?php print $head; ?>
<title><?php print $head_title; ?></title>
<style type="text/css">
  body {
    color:#444;
    background:#fff;
    font-family:sans-serif;
    margin:0 auto;
    padding:20px;
  }
</style>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
<?php if ($site_name): ?>
  <h1 id="site-name"><?php print $site_name; ?></h1>    
<?php endif; ?>
<?php if ($title): ?>
  <h2 class="title"><?php print $title; ?></h2>
<?php endif; ?>
<?php print $content; ?>
</body>
</html>
