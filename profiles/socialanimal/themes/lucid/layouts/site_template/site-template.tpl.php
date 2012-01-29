<?php
/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>

<div id="page">
  <?php if (!empty($content['branding'])): ?>
    <header class="branding" role="banner">
      <div class="container-12 clearfix">
        <div class="grid-12 clearfix">
          <?php print render($content['branding']); ?>
        </div>
      </div>
    </header>
  <?php endif; ?>
  
  <?php if (!empty($content['content'])): ?>
    <div class="main" role="main">
      <div class="container-12 clearfix">
        <div class="grid-12 clearfix">
          <?php print render($content['content']); ?>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if (!empty($content['closure'])): ?>
    <footer class="closure" role="contentinfo">
      <div class="container-12 clearfix">
        <div class="grid-12 clearfix">
          <?php print render($content['closure']); ?>
        </div>
      </div>
    </footer>
  <?php endif; ?>
</div>
