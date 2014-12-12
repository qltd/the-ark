(function ($) {
  Drupal.behaviors.theArkExpandableDetails = {
    attach: function () {
      var expanders = $('.expandable-details-title')
        , items = $('.expandable-details-item');

      if (!expanders.length || !items.length) return;

      items.addClass('expandable-details-item-collapsed');
      expanders.on('tap', function () {
        $(this).parents('.expandable-details-item').toggleClass('expandable-details-item-collapsed');
      });
    }
  };
})(jQuery);
