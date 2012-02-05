(function ($) {

// Music player hide/display function
    Drupal.behaviors.SaMusicToggle = {
    attach: function (context, settings) {
      $("#music-player .player-hide-show", context).click(function(e) {
        $('.views-field-field-music-image, .views-field-title').toggle('fast');
        // We can not toggle jp-playlist because the elements needs to be visible
        // for the player scripts to work properly. so we toggle a class and do
        // some css magic instead.
        $('.jp-playlist').toggleClass('playlist-hidden');
      })
    }
  }

// Scale text function
  Drupal.behaviors.saFitText = {
    attach: function (context, settings) {
      $(".pane-page-site-name .pane-content").fitText((0.8), { minFontSize: '50px', maxFontSize: '130px' });
    }
  }

})(jQuery);(500);