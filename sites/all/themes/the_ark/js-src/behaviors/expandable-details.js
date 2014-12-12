(function ($) {

  function expandableDetailsToggle (elem) {
    var parent = elem.parents('.expandable-details-item')
      , expander = parent.find('.expandable-details-expander')
      , expanderLabel = expander.length && expander.attr('data-expander-label') ?
          expander.attr('data-expander-label') :
          'Item';

    if (parent.hasClass('expandable-details-item-collapsed'))
      expander.text('Close ' + expanderLabel);
    else
      expander.text('View ' + expanderLabel);

    parent.toggleClass('expandable-details-item-collapsed');
  }

  Drupal.behaviors.theArkExpandableDetails = {
    attach: function () {
      var expanders = $('.expandable-details-title, .expandable-details-expander')
        , items = $('.expandable-details-item');

      if (!expanders.length || !items.length) return;

      $('.expandable-details-expander').each(function (index, expander) {
        expandableDetailsToggle($(expander));
      });

      expanders.on('tap', function () {
        expandableDetailsToggle($(this));
      });
    }
  };
})(jQuery);
