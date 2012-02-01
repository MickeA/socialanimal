<?php
/**
 * @file
 * This layout is intended to be used inside the page content pane. Thats why
 * there is not wrapper div by default.
 */
?>

<div id="page">
  <div class="page-inner">
    <header class="header" role="banner">
       <?php if (!empty($content['navigation'])): ?>
          <div class="container-12 clearfix navigation">
            <div class="grid-12 clearfix">
              <?php print render($content['navigation']); ?>
            </div>
          </div>
       <?php endif; ?>
    </header>

    <?php if (!empty($content['content'])): ?>
      <div class="main" role="main">
        <div class="container-12 clearfix">
          <div class="grid-12 clearfix">
            <?php print render($content['content']); ?>
          </div>
        </div>
      </div>
    <?php endif; ?>
  </div>
</div>
  <?php if (!empty($content['closure'])): ?>
    <footer class="closure clearfix" role="contentinfo">
        <div class="container-12 clearfix footer">
          <div class="grid-12 clearfix footer-inner">
            <?php print render($content['closure']); ?>
          </div>
        </div>
    </footer>
  <?php endif; ?>