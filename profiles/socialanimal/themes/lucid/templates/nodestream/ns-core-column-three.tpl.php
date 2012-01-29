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

<?php if (!empty($content['header_beta']) || !empty($content['main']) || !empty($content['aside_alpha']) || !empty($content['footer_alpha']) || !empty($content['footer_beta'])): ?>
  <div class="page-main grid-9 alpha">
  <?php endif; ?>

  <?php if (!empty($content['header_beta'])): ?>
    <header class="header-beta grid-9 alpha omega">
      <?php print render($content['header_beta']); ?>
    </header>
  <?php endif; ?>

  <?php if (!empty($content['main'])): ?>
    <div class="main grid-6 alpha">
      <?php print render($content['main']); ?>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['aside_alpha'])): ?>
    <aside class="aside-alpha grid-3 omega">
      <?php print render($content['aside_alpha']); ?>
    </aside>
  <?php endif; ?>

  <?php if (!empty($content['footer_alpha'])): ?>
    <footer class="footer-alpha grid-9 alpha omega">
      <?php print render($content['footer_alpha']); ?>
    </footer>
  <?php endif; ?>

  <?php if (!empty($content['header_beta']) || !empty($content['main']) || !empty($content['aside_alpha'])): ?>
  </div>
<?php endif; ?>

<?php if (!empty($content['aside_beta'])): ?>
  <aside class="aside-beta grid-3 omega">
    <?php print render($content['aside_beta']); ?>
  </aside>
<?php endif; ?>

<?php if (!empty($content['footer_beta'])): ?>
  <footer class="footer-beta grid-12 alpha omega">
    <?php print render($content['footer_beta']); ?>
  </footer>
<?php endif; ?>
