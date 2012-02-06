(function ($) {

  Drupal.behaviors.filtersieModule = {
    attach: function (context, settings) {
      var This = this;
      var matrixInputs = $('#edit-data-matrix input', context);
      this.sumEntrie(matrixInputs, context);
      matrixInputs.change(function() {        
        This.sumEntrie(matrixInputs, context);
      });      
    },  
    sumEntrie: function(entries, context) {
      var out = 0;
      $.each(entries, function(index,entry){        
        var f = parseFloat($(entry).val());
        out+=f?f:0;
      });
      $('#filtersie_matrix_sum', context).html(out);
      return out;
    }
  };

})(jQuery);
