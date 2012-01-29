<?php
/**
 * @file
 * Override of the site template layout provided by ns_core
 */
?>

<div id="page">
  <header id="header" role="banner">
    <?php if (!empty($content['branding'])): ?>
      <div class="container-12 clearfix">
        <div class="grid-12 clearfix">
          <?php print render($content['branding']); ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!empty($content['nav'])): ?>
      <div id="navigation" role="navigation">
        <div class="container-12 clearfix">
          <div class="grid-12 clearfix">
            <?php print render($content['nav']); ?>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </header>
  <?php if (!empty($content['main'])): ?>
    <div id="main" role="main">
      <div class="container-12 clearfix">
        <div class="grid-12 clearfix">
          <?php print render($content['main']); ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['footer'])): ?>
    <footer id="footer">
      <div class="container-12 clearfix">
        <div class="grid-12 clearfix">
          <?php print render($content['footer']); ?>
        </div>
      </div>
    </footer>
  <?php endif; ?>
</div>
