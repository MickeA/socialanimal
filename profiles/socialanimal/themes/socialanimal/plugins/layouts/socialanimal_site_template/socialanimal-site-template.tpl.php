<?php

/**
 * @file
 * This layout is designed to be the site template layout when using
 * the Panels Everywhere module.
 */
?>
<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="page-wrapper">
  
  <div class="non-footer-wrapper">
    <?php if (!empty($content['branding'])): ?>
      <div class="page-branding-wrapper">
        <div class="region container-16 clearfix">
          <div class="page-branding grid-16">
            <div class="page-branding-inner clearfix">
              <?php print render($content['branding']); ?>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!empty($content['nav'])): ?>
      <div class="page-nav-wrapper">
        <div class="region container-16 clearfix">
          <div class="page-nav grid-16">
            <div class="page-nav-inner clearfix">
              <?php print render($content['nav']); ?>
            </div>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <?php if (!empty($content['main']) || !empty($content['aside_alpha'])): ?>
      <div class="page-body-wrapper">
        <div class="region container-16 clearfix">

            <?php if (!empty($content['main'])): ?>
              <div class="page-body grid-10">
                <div class="page-body-inner clearfix">
                  <?php print render($content['main']); ?>
                </div>
              </div>
            <?php endif; ?>

            <?php if (!empty($content['aside_alpha'])): ?>
              <div class="page-aside-alpha grid-6">
                <div class="page-aside-alpha-inner clearfix">
                  <?php print render($content['aside_alpha']); ?>
                </div>
              </div>
            <?php endif; ?>

        </div>
      </div>
    <?php endif; ?>
    <div class="sticky-footer-push"></div>
  </div>

  <?php if (!empty($content['footer'])): ?>
    <div class="page-closure-wrapper">
      <div class="region container-16 clearfix">
        <div class="page-closure grid-16">
          <div class="page-closure-inner clearfix">
            <?php print render($content['footer']); ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

</div>
