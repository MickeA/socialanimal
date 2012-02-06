(function ($) {

  Drupal.behaviors.semanticPanelsEq_Height = {
    attach: function (context) {

      $('div.equalBlocks-wrapper', context).children().equalBlocks();

    }
  }

})(jQuery);