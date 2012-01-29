<?php
/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>
<?php if (!empty($content['header_alpha'])): ?>
  <header class="header-alpha grid-12 alpha omega">
    <?php print render($content['header_alpha']); ?>
  </header>
<?php endif; ?>

<?php if (!empty($content['header_beta'])): ?>
  <header class="header-beta grid-12 alpha omega">
    <?php print render($content['header_beta']); ?>
  </header>
<?php endif; ?>

<?php if (!empty($content['main'])): ?>
  <div class="main grid-12 alpha omega" role="main">
    <?php print render($content['main']); ?>
  </div>
<?php endif; ?>

<?php if (!empty($content['footer_alpha'])): ?>
  <footer class="footer-alpha grid-12 alpha omega">
    <?php print render($content['footer_alpha']); ?>
  </footer>
<?php endif; ?>
